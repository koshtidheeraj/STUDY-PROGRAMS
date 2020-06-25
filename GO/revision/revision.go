package main

import (
	"fmt"
	// "time"
)

func add(x,y int) (a int, b int) {
	a = 10
	b = 20
	return
}
func closure() func(int)(int) {
	sum := 5
	b := func(a int)(int) {
		sum = sum + a;
		return sum
	}
	return b
}
type vertexinterface interface {
	vertexprint()
}
type vertex struct {
	x int
	y int
}
func(v vertex)vertexprint() {
	fmt.Println(v.x)
	fmt.Println(v.y)
}
func(v vertex)vertexchange() {
	temp := v.x
	v.x = v.y
	v.y = temp
}

func say(s string, c chan int) {
	<-c
	fmt.Println(s)
	c<-1
}

func main() {
	c := make(chan int)
	go say("hello", c)
	say("world",c) 
	c<-2
	<-c
	// var v = vertex{2,4}
	// var vptr *vertex = &v
	// var vertexintfc vertexinterface
	// vertexintfc = vptr
	// vertexintfc.vertexprint()
	// vptr.vertexchange()
	// vptr.vertexprint()

	
	// vptr.vertexchange()
	// vptr.vertexprint()

	// fmt.Println("hello world")
	// fmt.Println(add(3,4))
	// var i int = 3
	// fmt.Printf("i is type of %T \n", i)
	// const pi = 3.142
	// j:= 0
	// if fmt.Println("for loop start");true {
	// 	for j<2  {
	// 		fmt.Println(pi)
	// 		j++
	// 	}
	// }
	// k := 3
	// switch k{
	// case 1:
	// 	fmt.Println("I am one")
	// default:
	// 	fmt.Println("I am default")
	// }

		// var arr [2]int
	// arr[0] = 1
	// fmt.Println(arr)

	// var primes = [10]int {1,2,3}
	// var primeslice = primes[:4]
	// fmt.Println(primeslice)
	// a := make([]int,2,3)
	// fmt.Println(len(a), cap(a) )
	// a = append(a,1)
	// fmt.Println(len(a), cap(a) )
	// for i, val := range a{
	// 	fmt.Println(i,val)
	// }
	// var a2 map[string]string
	// a2 = make(map[string]string)
	// a2["dheeraj"] = "shweta"
	// ele, ok := a2["dheeraj"] 
	// if ok {
	// 	fmt.Println(ele)
	// }

	// closureinst := closure()
	// fmt.Println(closureinst(3))
}