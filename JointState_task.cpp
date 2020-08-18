// Task 1:
// JointState is a class described by vectors name and position. For each element in the
// name vector there is a corresponding position value of this joint at the same index in vector
// position.

// Objects are considered equal if:
// - name vectors are the same size and contain the same joint names. This does not
// mean they have same order
// - position vectors are the same size
// - for each name-position entry in first object there is an equal name-position entry in
// second object
// - for the same joint |pos1 - pos2| < tolerance


// For example, these joint states are considered equal:
// first_joint_state.name = {"joint1", "joint2", "joint3"};
// first_joint_state.position = {1, 2, 3};
// second_joint_state.name = {"joint2", "joint3", "joint1"};
// second_joint_state.position = {2, 3, 1};


#include <iostream>
#include <vector>
#include <map>
#include <cmath>
//#include <exception>

class JointState
{
public:
	std::vector<std::string> name;
	std::vector<double> position;
};


// Complete function areEqualJointStatePositions which compares two JointState objects.
bool areEqualJointStatePositions(const JointState& first_joint_state, const JointState& second_joint_state, double tolerance)
//const reference to JointState object this doesn't make a copy and the function can't change the variables
//comparison function so should never manipulate the data in the class itself
{
	//check sizes first for efficency
	if (first_joint_state.name.size() != second_joint_state.name.size())
		return false;

	if (first_joint_state.position.size() != second_joint_state.position.size())
		return false;

	//if both vector sizes are equal create a map for the second_joint_state as they are in pairs
	std::map<std::string, double> second_js_map;
	for (int i=0; first_joint_state.name.size(); i++)
	{
		second_js_map[second_joint_state.name[i]] = second_joint_state.position[i];
	}
	// check that all the joint names in the first are in the second
	for (int i=0; first_joint_state.name.size(); i++) 
	{
		std::map<std::string, double>::iterator joint_pair = second_js_map.find(first_joint_state.name[i]); 
		if (joint_pair == second_js_map.end()) { //can't find a match so definetly incorrect
			return false;
		}
		// Confirm tollerance
		else if (std::abs(first_joint_state.position[i] - joint_pair->second) > tolerance) //checking the matched pair for tolerance
			return false;

	}

	return true;
}

int main()
{
	JointState first_joint_state, second_joint_state;


	first_joint_state.name = { "joint5", "joint1", "joint2", "joint3", "joint4", "joint6" };
	first_joint_state.position = { 5, 1, 2, 3, 4, 6 };
	second_joint_state.name = { "joint2", "joint4", "joint3", "joint1", "joint6", "joint5" };
	second_joint_state.position = { 2, 4, 3, 1, 6, 5 };

	bool answer = areEqualJointStatePositions(first_joint_state, second_joint_state, 0.435);

	if (answer == true) {
		std::cout << "Joint states are equal" << std::endl;
	}
	else {
		std::cout << "Joint states are NOT equal" << std::endl;
	}


	return EXIT_SUCCESS;
}



