#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>
#include <string>


class MotorController {
public:
    MotorController()
    {
        ros::NodeHandle nh;
        cmd_vel_sub_ = nh.subscribe("/cmd_vel", 100, &MotorController::cmdVelCallback, this);
        cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("/cmd_vel_ctrl", 10);
    }


    void cmdVelCallback(const geometry_msgs::Twist &msg)
    {
        pub_msg_.linear.x = msg.linear.x * 2.0;
        pub_msg_.angular.z = msg.angular.z / 2.0;
        cmd_vel_pub_.publish(pub_msg_);
//        ROS_INFO("subscribe: %f, %f", msg.linear.x, msg.angular.z);
        ROS_INFO("publish: %f, %f", pub_msg_.linear.x, pub_msg_.angular.z);
    }


private:
    ros::Subscriber cmd_vel_sub_;
    ros::Publisher cmd_vel_pub_;
    geometry_msgs::Twist pub_msg_;
};


int main(int argc, char *argv[]) {
    ros::init(argc, argv, "motor_controller");
    MotorController mc;

    ros::spin();
    return 0;
}
