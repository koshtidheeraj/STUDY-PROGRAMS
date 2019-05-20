package main

import (
	"fmt"
)

func sum(a []int, c chan int) {
	sum := 0
	for _, val := range a {
		sum += val
	}
	c <- sum
}
func printInSync(c, quit chan int) {
	var temp int
	// select statement waits untill one of its cases is ready for run and in case multiple 
	// cases are ready at time one of them is randomly picked up and executed.
	select {
	case temp <- c:	
		fmt.Println(temp)
	case quit<-temp:
		fmt.Println()
	}
}
func main() {
	array := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	c := make(chan int)
	// make (chan int, 4) this call creates channel with capacity of 4 elements when
	// 4 elements are filled then any further input is not taken untill something is
	// removed from the channel
	go sum(array[:4], c)
	go sum(array[5:], c)

	x, y := <-c, <-c
	fmt.Println("final summation = ", x, y, x+y)
}