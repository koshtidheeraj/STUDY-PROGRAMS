// You can edit this code!
// Click here and start typing.
package main

import (
	"fmt"
)

type book struct {
	title  string
	author string
}

type sampleinterface interface {
	function1() int
}

type sampleconcrete struct {
	a int
}

func (sampleinst sampleconcrete) function1() int {
	fmt.Println("sample concrete called")
	return 1
}
func main() {
	var i sampleinterface
	var inst sampleconcrete
	inst.a = 2
	i = inst
	i.function1()

	t, ok := i.(sampleconcrete)
	if ok {
		fmt.Println(t.a)
	}

	// struct example
	// var book1 book
	// book1.author = "dheeraj"
	// book1.title = "my family"
	// printbook(book1)
	// book1.printauthor(2)

	// array declaration
	// var numbers []int
	// fmt.Println(numbers)

	// var num2 = make([]int, 3, 5)

	// Map example
	// var countrycapmap map[string]string
	// countrycapmap = make(map[string]string)
	// countrycapmap["india"] = "delhi"
	// countrycapmap["russia"] = "moscow"
	// fmt.Println(countrycapmap)
	// delete(countrycapmap, "india")
	// for country := range countrycapmap {
	// 	fmt.Println(countrycapmap[country])
	// }

	// named return
	// i,j := namedreturn()
	// fmt.Print("named return values",i,"  ",j)

	// variable inintialisation
	// var i,j int = 3,4
	// fmt.Println(i)

	// constant declaration
	// const ct float32= 2.3
	// fmt.Println(ct)

	// use of form loop as while loop
	// sum := 1
	// fmt.Println(sum, reflect.TypeOf(sum))
	// for sum < 5 {
	// 	fmt.Println(sum)
	// 	sum = sum + 1
	// }

	// if can have small statemennt before condition
	// a := 3
	// if dk := "dheeraj"; a < 4 {
	// 	fmt.Println(dk, a)
	// }

	// switch statement
	// switch os := runtime.GOOS; os {
	// case "darwin":
	// 	fmt.Println("mac")
	// case "linux":
	// 	fmt.Println("linux")
	// default:
	// 	fmt.Println("others")
	// }switch os := runtime.GOOS; os {
	// case "darwin":
	// 	fmt.Println("mac")
	// case "linux":
	// 	fmt.Println("linux")
	// default:
	// 	fmt.Println("others")
	// }

	// defer will execute when surrounding function completes
	// defer fmt.Println("deferred call 1")
	// defer fmt.Println("deferred call 2")
	// fmt.Println("main call")

	// slice example
	// slc := []int{1,2,3}
	// fmt.Println(slc)

	// map example
	// var mapinst = map[string]string{"first": "one"}
	// fmt.Println(mapinst)

	// var arr = [5]int {1,2,3,4,5}
	// fmt.Println(arr)

	// array
	// var arr [5]int;
	// arr[0] = 1
	// fmt.Println(arr)

	// slice
	// var arr []int;
	// arr = make([]int, 3,3)
	// fmt.Println(arr)
}

func (bookinst book) printauthor(i int) int {
	fmt.Println("received value")
	fmt.Println(i)
	fmt.Println(bookinst.author)
	return 1
}
func printbook(book1 book) {
	fmt.Println(book1.title)
}

func namedreturn() (x, y int) {
	x = 2
	y = 4
	return
}
