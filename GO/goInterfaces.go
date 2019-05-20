package main

import (
	"fmt"
)

type vertex struct {
	x int
	y int
}
type absinterface interface {
	multtwo() int
}

type intfc interface{} // empty interface which can get assigned to any type

func (v *vertex) multtwo() int {
	if v != nil { // If this nil check is not handled then there will be runtime error
		// becacuse there is no concrete object assigned to v
		return v.x * v.y
	} else {
		return 1
	}
}

func doInterfaceCall(interface1 interface{}) {
	switch interface1.(type) {
	case int:
		fmt.Println("integer type")
	case string:
		fmt.Println("string type")
	default:
		fmt.Println("no type")
	}
}
func main() {
	var a absinterface
	v := vertex{3, 4}
	vptr := &v
	// Below line will give compiler error because multtwo method is on receiver
	// of vertex pointer not object
	// a = v
	a = vptr
	fmt.Println()

	// calling method on interface having nil concrete value will be handled gracefully.
	var vptr2 *vertex
	a = vptr2 // vptr is not pointing to any concrete type
	a.multtwo()

	var intfcInst intfc
	intfcInst = "hello"
	s, ok := intfcInst.(string)
	fmt.Println(s, ok)
	f, ok2 := intfcInst.(float64)
	fmt.Println(f, ok2)
	// f = intfcInst.(float64)  intfcInst does not contain float64 so this will
	// give runtime error

	doInterfaceCall(3)
	doInterfaceCall("dheeraj")
	doInterfaceCall(3.1)
}
