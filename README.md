# Multi-Threaded-Sorter
C Multi-Threading via Posix Threads (pthreads) to sort a large amount of data

## Overview
* Read in the IMDB movie metadata CSV files and sort the data in them
* Scan through the directory it is called on and sort each file in that directory and all files in all subdirectories
* Spawn a new thread to search each directory and sort each file with mergesort
* The sorted output of all files will go to a single output file
* Each thread will output the number of threads it created along with their threadIDs. 
* Analysis between threads and processes for multicomputing

## Usage 
*  `-c` indicates sorting by a column. The files read in by your code should be sorted by the column name that immediately follows '-c'. This flag is required
*  `-d` indicates a starting directory. The program will start at this directory name immediately following '-d' to look for CSV files to sort. This flag is optional
*  `-o` indicates the output directory for the sorted file. The program will store the sorted file to the directory name immediately following the '-o'. This flag is optional
