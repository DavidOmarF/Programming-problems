package main

import (
	"fmt"
)

func main() {
	var dnaString string
	t := [4]int{0, 0, 0, 0}
	i := 0
	fmt.Scanln(&dnaString)
	fmt.Println(dnaString)
	for ; i < len(dnaString); i++ {
		if dnaString[i:i+1] == "A" {
			t[0]++
		} else if dnaString[i:i+1] == "C" {
			t[1]++
		} else if dnaString[i:i+1] == "G" {
			t[2]++
		} else if dnaString[i:i+1] == "T" {
			t[3]++
		}
	}
	fmt.Println(t)
}
