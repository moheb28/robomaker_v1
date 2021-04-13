#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

using namespace std;


unsigned int microsecond = 1000000;
geometry_msgs::Twist msg1;
geometry_msgs::Twist msg2;


 int i = 0;

int main(int argc, char **argv)
{

    ros::init(argc, argv, "turtle_control");
    ros::NodeHandle nodehand ;

    ros::Publisher my_publisher;
    my_publisher = nodehand.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

    ros::Rate loop_rate(10);

    bool move;



    int count = 0;
    while(ros::ok()){


            msg1.linear.x = 1;
            my_publisher.publish(msg1);
            msg1.angular.z = 0;
            ros::spinOnce();
            ROS_INFO_STREAM(msg1);
            usleep(1 * microsecond);

        
        if (i % 2 == 0)
        {

            msg1.linear.x = 1;
            msg1.angular.z = -3.14;
            my_publisher.publish(msg1);
            ROS_INFO_STREAM(i);
            ROS_INFO_STREAM("msg1");
            //ros::spinOnce();
            usleep(1 * microsecond);
            i = i + 1;

        }
        else
        {
            msg1.linear.x = 1;
            msg1.angular.z = 3.1415;
            my_publisher.publish(msg1);
            ROS_INFO_STREAM(i);
            //ros::spinOnce();
            usleep(1 * microsecond);
             i = i + 1;

        }

            

        //ros::spinOnce();
        loop_rate.sleep();
        ++count;


    }
}
