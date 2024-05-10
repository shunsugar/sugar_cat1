#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>
#include <string>


int main(int argc, char *argv[]) {
    ros::init(argc, argv, "motor_talker");
    ros::NodeHandle nh;
    ros::Publisher pub_ = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Rate loop_rate(10);

    while(ros::ok()) {
        geometry_msgs::Twist cmd_vel;
        cmd_vel.linear.x = 2.0;
        cmd_vel.angular.z = 0.20;
        ROS_INFO("publish: %f, %f", cmd_vel.linear.x, cmd_vel.angular.z);
        pub_.publish(cmd_vel);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
