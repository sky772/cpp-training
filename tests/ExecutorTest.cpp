#include <gtest/gtest.h>

#include <memory>
#include <tuple>

#include "Executor.hpp"

namespace adas
{

bool operator==(const Pose& lhs, const Pose& rhs)
{  // 为 Pose 定义 == 运算符重载，便于在测试中比较 Pose 对象
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}

// 测试用例：当没有命令时，应返回初始位姿
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

    // when

    // then
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());
    // then
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas
