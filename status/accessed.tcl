#!/usr/bin/tclsh
#will have to change the above line for different locations
#
#execute: ./accessed.tcl <filename> <filename> <filename>
#
#AUTHOR BHARGAVA NARAYANA
#
#Advantages of this implementation over the C program:
#lesser code
#advantags of scripting languge
#library functions used(code reused)
#case senstive bug not seen here
#number of file compared can be changed using NUM_OF_FILES flag
#
#Disadvantages:
#TCL has to be installed to run
#disadvantages of scripting language
#
#change this value to change number of files.
set NUM_OF_FILES 3

if { $::argc ==  $NUM_OF_FILES } {
        set i 1
        foreach arg $::argv {
               set file_$i $arg
               if {[file exists $arg] ne 1} {
                       puts "***ERROR: $arg not found**"
               }
               set atime_file_$i [file atime $arg]
               incr i
         }
 } elseif {$::argc < $NUM_OF_FILES} {
        puts "\t**ERROR: not enough arguments*** "
} else {
        puts "\t***ERROR: invlaid arguments***"
}
set latest [expr {max($atime_file_1, $atime_file_2, $atime_file_3)}]
if {$latest == $atime_file_1} {
        puts "$file_1"
} elseif {$latest == $atime_file_2} {
        puts "$file_2"
} else {
        puts "$file_3"
}
