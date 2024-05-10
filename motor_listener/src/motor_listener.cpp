#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>


void cmdVelCallback(const geometry_msgs::Twist &msg)
{
    ROS_INFO("subscribe: %f, %f", msg.linear.x, msg.angular.z);
}


int main(int argc, char *argv[]) {
    ros::init(argc, argv, "motor_listener");
    ros::NodeHandle nh;
    ros::Subscriber sub_ = nh.subscribe("/cmd_vel_ctrl", 10, cmdVelCallback);

    ros::spin();
    return 0;
}
