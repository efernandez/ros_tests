
#include <ros/ros.h>
#include <std_msgs/Int32.h>

class Node
{
public:
  Node()
    : nh_()
    , light_sub_(nh_.subscribe("light", 1, &Node::lightCallback, this))
    , heavy_sub_(nh_.subscribe("heavy", 1, &Node::heavyCallback, this))
    , sum_(0.0)
  {}

private:
  void lightCallback(const std_msgs::Int32ConstPtr& msg)
  {
    ROS_INFO_STREAM(__PRETTY_FUNCTION__ << " received message " << *msg);
  }

  void heavyCallback(const std_msgs::Int32ConstPtr& msg)
  {
    ROS_INFO_STREAM(__PRETTY_FUNCTION__ << " received message " << *msg);

    sum_ = 0.0;
    for (int i = 0; i < msg->data; ++i)
    {
      sum_ += std::pow(i, 3.0);
    }

    ROS_INFO_STREAM(__PRETTY_FUNCTION__ << " DONE (sum = " << sum_ << ")");
  }

  ros::NodeHandle nh_;
  ros::Subscriber light_sub_;
  ros::Subscriber heavy_sub_;

  double sum_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "test_no_async_spinner_node");

  Node node;

  ros::spin();

  return EXIT_SUCCESS;
}
