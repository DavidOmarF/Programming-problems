package main

import (
	"bufio"
	"fmt"
	"os"
)

func readFile(lineNumber int) string {
	f, _ := os.Open("test.txt")
	scanner := bufio.NewScanner(f)
	var line string
	i := 0
	for scanner.Scan() {
		if i == lineNumber {
			line = scanner.Text()
			break
		} else {
			i++
		}

	}
	return line
}

func invertString(dnaString []byte) []byte {
									// The middle of the string will be needed to stop swaping
	var middle int 							// values at that position. Otherwise, it will continue until 
									// ending with the very same string before inverting.
	if len(dnaString)%2 == 0 { 					// if the lenght of dnaString is even number, 
		middle = len(dnaString)/2 - 1				// the middle is the lenght / 2 - 1
	} else {
		middle = (len(dnaString)+1)/2 - 1			// otherwise, is (lenght + 1 ) / 2 - 1
	}
	for i := 0; i <= middle; i++ {					
		aux := dnaString[i]
		dnaString[i] = dnaString[len(dnaString)-i-1]
		dnaString[len(dnaString)-i-1] = aux
	}
	return dnaString
}

func main() {
	dnaString := []byte(readFile(0)) 				// Converts a string to an array of bytes and assigns
	for i := 0; i < len(dnaString); i++ {  				// it to dnaString
		if dnaString[i] == 'A' {
			dnaString[i] = 'T'
		} else if dnaString[i] == 'C' {
			dnaString[i] = 'G'
		} else if dnaString[i] == 'G' {
			dnaString[i] = 'C'
		} else if dnaString[i] == 'T' {
			dnaString[i] = 'A'
		}
	}
	fmt.Printf("%s\n", invertString(dnaString)) 			// Prints dnaString inverted, a.k.a. The Complement.
}
