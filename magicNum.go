package main

import (
	"fmt"
	"os"
	"log"
	"strconv"
	"strings"
	"bufio"
)

func numRepeat(num int) bool {
	statMap := make(map[int]bool)
	for i := 0; i < 10 ; i++ {
		statMap[i] = false
	}	
	
	for num != 0 {
		digit := num % 10 
		num   =  num/10
		if statMap[digit] == true {
			return true
		} else {
			statMap[digit] = true
		}
	}
	return false
}


func visitAll(num int) bool {
	statusMap := make(map[int]bool)

	numBak    := num
	numLen    := 0
	for numBak != 0 {
		numBak = numBak/10 
		numLen++
	}
	numList   := make([]int, 0)
	
	numBak    = num
	for numBak != 0 {
		digit := numBak % 10
		numBak = numBak/10 
		statusMap[digit] = false
		numList = append([]int{digit}, numList...)
	}
	
	index := 0
	for visitCount := 0; visitCount < numLen; {
		if statusMap[numList[index]] == true {
			return false
		}
		statusMap[numList[index]] = true
		
                shift := index
                index = numList[index]
		for index > len(numList) {
			index = index - len(numList)
		}
		
		shift = shift + index
		for shift >= len(numList) {
			shift  = shift - len(numList) 
		}		
		index = shift
		visitCount = visitCount + 1
	}
	
	for _, status := range statusMap {
		if status == false {
			return false
		} 
	}	

	if index != 0 {
		return false
	}
	
	// now roll over the digits of the number. 
	return true
} 

func isMagic(num int) bool {
	if numRepeat(num) {
		return false
	}
	
	if visitAll(num) == false {
		return false
	}
	
	// If the other two are satisfied its true and is magic
	return true
}	

func displayRes(list []int) {
    if len(list) == 0 {
	fmt.Print("-1");
    }
    for _, val := range list {
	fmt.Print(val, " ")
    }
    fmt.Print("\n")
}

func main() {
    file, err := os.Open(os.Args[1])
    if err != nil {
        log.Fatal(err)
    }   
    defer file.Close()
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        //'scanner.Text()' represents the test case, do something with it

	splitStr := strings.Split(scanner.Text(), " ")
	A, _ := strconv.Atoi(splitStr[0])
	B, _ := strconv.Atoi(splitStr[1])
	magicList := make([]int, 0)
	
	for num := A; num <= B; num++ {
		if isMagic(num) {
			magicList = append(magicList, num)
		}
	}
	displayRes(magicList)
    }   
}
