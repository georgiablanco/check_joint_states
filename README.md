# check_joint_states
C++ code to check joint states 

# Interview Task

Task 1:
JointState is a class described by vectors name and position. For each element in the
name vector there is a corresponding position value of this joint at the same index in vector
position.  

class JointState {
public:
std::vector<std::string> name;
std::vector<double> position;
};
Complete function areEqualJointStatePositions which compares two JointState objects.
bool areEqualJointStatePositions(const JointState& first_joint_state, const JointState&
second_joint_state, double tolerance)
{
// write your code here
}
Objects are considered equal if:  
- name vectors are the same size and contain the same joint names. This does not
mean they have same order  
- position vectors are the same size  
- for each name-position entry in first object there is an equal name-position entry in
second object  
- for the same joint |pos1 - pos2| < tolerance  
                                              
For example, these joint states are considered equal:
first_joint_state.name = {"joint1”, “joint2”, “joint3"};
first_joint_state.position = {1, 2, 3};
second_joint_state.name = {"joint2”, “joint3", "joint1"};
second_joint_state.position = {2, 3, 1}
