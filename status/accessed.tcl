#!/usr/bin/tclsh
#will have to change the above line for different locations
#
#AUTHOR BHARGAVA NARAYANA
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
