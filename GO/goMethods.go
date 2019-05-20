package main

import (
	"fmt"
)

type vertex struct {
	x int
	y int
}
type myfloat float64

func (v vertex) add() int {
	return v.x + v.y
}
func (v *vertex) addonebypointer() {
	v.x = v.x + 1
	v.y = v.y + 1
}
func (v vertex) addonebyvalue() {
	v.x = v.x + 1
	v.y = v.y + 1
}
func addAsArgument(v vertex) int {
	return v.x + v.y
}
func (f myfloat) mult2() float64 {
	return float64(f * 2)
}
func main() {
	v := vertex{1, 2}
	fmt.Println("addition of vertices", v.add())
	vptr := &v
	fmt.Println("addition of vertices", vptr.add())
	// In above statement vptr is pointer which is sent as a reveiver.
	// Even if add does not have pointer receiver, it will work.
	// Same argument is not true for pointer argument. This is explained in below code
	fmt.Println("addition of vertices as argument", addAsArgument(v))
	// fmt.Println("addition of vertices as argument", addAsArgument(vptr)) // This line causes error

	// methods can act on numeric types
	f := myfloat(4.5)
	fmt.Println("mult float by 2", f.mult2())

	// When you call method by pointer receiver original object gets midified.
	// When yuo call method by value receiver then local copy of object gets modified.
	v1 := vertex{5, 6}
	fmt.Println("before add by value", v1)
	v1.addonebyvalue()
	fmt.Println("after add by value", v1)
	v1 = vertex{5, 6}
	vptr1 := &v1
	fmt.Println("before add by pointer", v1)
	vptr1.addonebypointer()
	fmt.Println("after add by pointer", v1)
}
