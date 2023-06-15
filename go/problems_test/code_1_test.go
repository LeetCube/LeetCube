package problems_test

import (
	"testing"

	"github.com/LeetCube/LeetCube/go/problems"
)

func Test1Smoke1(t *testing.T) {
	nums := []int{2, 7, 11, 15}
	target := 9
	if res := problems.TwoSum(nums, target); res[0] != 0 || res[1] != 1 {
		t.Errorf("Smoke 1 Failed.")
	}
}

func Test1Smoke2(t *testing.T) {
	nums := []int{3, 2, 4}
	target := 6
	if res := problems.TwoSum(nums, target); res[0] != 1 || res[1] != 2 {
		t.Errorf("Smoke 2 Failed.")
	}
}

func Test1Smoke3(t *testing.T) {
	nums := []int{3, 3}
	target := 6
	if res := problems.TwoSum(nums, target); res[0] != 0 || res[1] != 1 {
		t.Errorf("Smoke 3 Failed.")
	}
}
