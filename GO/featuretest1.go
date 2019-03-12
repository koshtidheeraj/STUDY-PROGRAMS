package main

import (
	"fmt"
	"math"
)

var i, j int = 1, 2 // var with initializer and type
// o,p := 7,8 implicit type without var (:=) [Not available outside function]
var r int // default value inside package is given 0

func swap(a, b string) (string, string) {
	return b, a
}
func main() {
	// fmt.Println(math.pi) // exported variables from package start with capital so
	// there is an error.
	var k, l = 3, 4 //  var with initializer and no type
	m, n := 5, 6    // implicit type without var [Available inside function]
	var q int       // default value inside function is given 0
	fmt.Println(math.Pi)
	fmt.Println(swap("dheeraj", "sayali"))
	fmt.Println(i, j, k, l, m, n)
	fmt.Println(q)
	fmt.Println(r)

	var s float32 = 3.14
	var t float64 = float64(s) // Here explicit float64 conversion is mandatory.
	fmt.Println(t)

	const pi int = 5 // := assignment is not allowed for const
	fmt.Println(pi)

	i := 0
	for i < 3 {
		fmt.Println("loop iteration")
		i++
	}
	// for {} // infinite loop
	if fmt.Println("code before if condition"); 1 < 2 {
		fmt.Println("one is less than 2")
	}

	cond := "one"
	switch cond {
	case "one":
		fmt.Println("switch for one")
	case "two":
		fmt.Println("switch foor two")
	default:
		fmt.Println("default")
	}

	// Switch without a condition is the same as switch true.
	var cond1 int = 4
	switch {
	case cond1 < 5:
		fmt.Println("cond1 is less than 5")
	case cond1 > 5:
		fmt.Println("cond1 is greater than 5")
	default:
		fmt.Println("cond1 is equal to 5")
	}

	//Deferred function calls are pushed onto a stack.
	// When a function returns, its deferred calls are executed in last-in-first-out order.
	for index := 0; index < 5; index++ {
		defer fmt.Println(index)
	}
	fmt.Println("above deferred functions are called");
}

// basic sata types in go are:
// bool
// string
// int, int8, int16, int32, int64
// uint, uint16, uint32, uint64 uintptr
// byte [int8 alias]
// rune [int32 alias unicode]
// float32, float64
// complex64, complex128
