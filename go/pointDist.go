package main

import (
	"fmt"
	"os"
	"log"
	"bufio"
	"strings"	
	"strconv"
	"math"
)

// A datatypre to hold point


type Point struct {

	X int;
	Y int;
}

func MakePoint(argX int, argY int) (point *Point) {
	
	point = &Point {
		X : argX,
		Y : argY,
	     }
	return
}

func dist(p1 *Point, p2 *Point) int {

	xSq := math.Pow(float64(p1.X - p2.X), 2) 
	ySq := math.Pow(float64(p1.Y - p2.Y), 2)
	return int(math.Sqrt(xSq + ySq))
}

func getPoint(splitStr string) (point *Point) {
	cleanStr := strings.TrimPrefix(splitStr, "(")
	cleanStr  = strings.TrimSuffix(cleanStr, ")")
	
	strNums  := strings.Split(cleanStr, ",")
 	X, _ := strconv.Atoi(strings.TrimSpace(strNums[0]))
	Y, _ := strconv.Atoi(strings.TrimSpace(strNums[1]))
	
	return MakePoint(X, Y) 
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

	
	splitStr := strings.Split(scanner.Text(), ") (")

	p1 := getPoint(splitStr[0])
	p2 := getPoint(splitStr[1])
	fmt.Println(dist(p1, p2))

	//p1 := MakePoint(0, 0)
	//p2 := MakePoint(3, 4)
	//fmt.Println(dist(p1, p2))
	
    }   
}
