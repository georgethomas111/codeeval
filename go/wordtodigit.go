// Word to digit golang
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

var (
	MAXLINE = 10
)

func GetDigit(strIp string) int {

	switch {
	case strIp == "zero":
		return 0
	case strIp == "one":
		return 1
	case strIp == "two":
		return 2
	case strIp == "three":
		return 3
	case strIp == "four":
		return 4
	case strIp == "five":
		return 5
	case strIp == "six":
		return 6
	case strIp == "seven":
		return 7
	case strIp == "eight":
		return 8
	case strIp == "nine":
		return 9
	}
	return -1
}

func main() {

	file, err := os.Open(os.Args[1])
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		str := scanner.Text()
		inputs := strings.Split(str, ";")
		for _, input := range inputs {
			fmt.Printf("%d", GetDigit(input))
		}
		fmt.Println()
	}
}
