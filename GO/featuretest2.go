package main

import (
	"fmt"
)

type vertex struct {
	x int
	y int
}

func printSlice(s string, x []int) {
	fmt.Printf("%s len=%d cap=%d %v\n",
		s, len(x), cap(x), x)
}

func compute(function1 func(int, int) int) int {
	fmt.Println("function called")
	return function1(2, 1)
}

func main() {
	v1 := vertex{1, 2}
	v2 := vertex{x: 1}
	v3 := vertex{}
	ptr := &v1
	fmt.Println(v1.x)
	fmt.Println(v2)
	fmt.Println(v3)
	fmt.Println(ptr.x) // Here ideally we should write as *ptr.x but golang allow ptr.x
	fmt.Println(ptr)

	arr1 := [3]int{1, 2, 3}
	fmt.Println(arr1)
	var arr2 [4]int
	fmt.Println(arr2)

	primes := [7]int{1, 2, 3, 4, 5, 6, 7} // [7]int is array literal []int is slice
	s := primes[2:4]
	s[0] = 11 // slice is just a reference to array
	fmt.Println(s)
	slice1 := []int{8, 9, 10}
	fmt.Println(slice1)
	s2 := []int{11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
	fmt.Println(s2)
	s2 = s2[:7]
	fmt.Println(s2)
	s2 = s2[2:]
	fmt.Println(s2)
	s2 = s2[:]
	fmt.Println(s2)

	var nilslice []int // nil slice
	// var nilslice [3]int cannot convert nil to type [3]int
	if nilslice == nil {
		fmt.Println("nil slice")
	}

	a := make([]int, 0, 5)
	printSlice("a", a)
	c := a[:2]
	printSlice("c", c)
	// d := a[2:]  this is error because a has len=0
	d := c[2:]
	printSlice("d", d)

	// slices of slices
	iterslices := [][]int{
		[]int{21, 22, 23},
		[]int{31, 32, 33},
	}
	fmt.Println(iterslices)
	iterslices = append(iterslices, []int{41, 42, 43})
	fmt.Println(iterslices)

	var rangearray = [5]int{1, 2, 4, 8, 16}
	for i, v := range rangearray {
		fmt.Printf("index= %d and var = %d \n", i, v)
	}
	for _, v2 := range rangearray { // _ ignore the value
		fmt.Printf("var = %d \n", v2)
	}

	var map1 map[string]string
	map1 = make(map[string]string)
	map1["first"] = "dheeraj"
	fmt.Println(map1)
	var map2 = map[string]string{
		"first":  "dheeraj again",
		"second": "sayali again",
	}
	fmt.Println(map2)
	delete(map2, "first")
	v, ok := map2["first"]
	fmt.Println("value is ", v, "availability", ok)

	add := func(a, b int) int {
		c := a + b
		return c
	}
	subtract := func(a, b int) int {
		return a - b
	}
	compute(add)
	compute(subtract)
}
