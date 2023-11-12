#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

void quickSort(std::vector<int>& nums, int low, int high) 
{
    if (low >= high) 
    {
        return;
    }
    int lt = low, gt = high;
    int pivot = nums[low];
    int i = low + 1;
    while (i <= gt) 
    {
        if (nums[i] < pivot) 
        {
            //如果第二个数据小于第一个数据 则交换
            std::swap(nums[lt++], nums[i++]);
        }
        else if (nums[i] > pivot) 
        {
            //如果第二个数据大于第一个数据 则与最后一个交换
            std::swap(nums[i], nums[gt--]);
        } 
        else 
        {
            i++;
        }
    }
    quickSort(nums, low, lt - 1);
    quickSort(nums, gt + 1, high);
}

int main() 
{
    std::vector<int> nums;
    // 随机生成十万个数据
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1000000);
    for (int i = 0; i < 100000; ++i) {
        nums.push_back(dis(gen));
    }

    // 测试排序所用时间
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(nums, 0, nums.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    // 输出排序所用时间
    std::chrono::duration<double> diff = end - start;
    std::cout << "排序所用时间: " << diff.count() << " 秒" << std::endl;

    return 0;
}
