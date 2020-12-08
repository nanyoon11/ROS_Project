#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //set frame
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

//set position
  goal.target_pose.pose.position.x = 4.39026832581;
  goal.target_pose.pose.position.y = -5.89320755005;
  goal.target_pose.pose.position.y = 0.0;
  goal.target_pose.pose.orientation.w = 0.981716085312;
  ROS_INFO("Sending goal 1 ");

 ac.sendGoal(goal);

 ROS_INFO("Waiting for the result");
 ac.waitForResult();


  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Robot has arrived to the goal position");
  }
  else
  {
    ROS_INFO("The base failed to move forward 1 meter for some reason");
  }

  return 0;
}
 

//  void goals_function()
//   {

//     move_base_msgs::MoveBaseGoal goal;

//     goal.target_pose.pose.position.x = 4.39026832581;
//     goal.target_pose.pose.position.y = -5.89320755005;
//     goal.target_pose.pose.position.y = 0.0;
//     goal.target_pose.pose.orientation.w = 0.981716085312;
//     ROS_INFO("Sending goal 1 ");
    
//     // goal.target_pose.pose.position.x = 4.53367996216;
//     // goal.target_pose.pose.position.y = -4.058111190;
//     // goal.target_pose.pose.position.y = 0.0;
//     // goal.target_pose.pose.orientation.w = 0.798060218883;
//     // ROS_INFO("Sending goal2 ");
//   }