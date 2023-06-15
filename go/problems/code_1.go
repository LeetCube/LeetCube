package problems

func TwoSum(nums []int, target int) []int {
	m := make(map[int]int, len(nums))
	for i, v := range nums {
		if idx, exists := m[target-v]; exists {
			return []int{idx, i}
		}
		m[v] = i
	}
	return []int{}
}
