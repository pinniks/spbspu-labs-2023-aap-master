#include "counter_minimums.hpp"
#include <limits>
#include <stdexcept>

popov::countMinSt::countMinSt():
  count_(0),
  min(0)
{}
void popov::countMinSt::operator()(int a)
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  if (min == 0)
  {
    min = a;
  }
  if (a == min)
  {
    if (count_ == maxSize)
    {
      throw std::logic_error("Count is too much.");
    }
    ++count_;
  }
  else if (min > a)
  {
    count_ = 1;
    min = a;
  }
}
size_t popov::countMinSt::operator()()
{
  return count_;
}