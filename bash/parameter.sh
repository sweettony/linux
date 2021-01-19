#!/bin/sh


#process substring

string='012345676543210'

#offset is integer that is not less zero
#len is the same as offset
#string range [offset, offset+len-1]
substr=${string:7:2}
echo '${string:7:2}'"= ${substr}"


#@offset is integer that is not less zero
#@len is less than zero, it is interpreted as an oﬀset in characters from the end of
#the value of parameter rather than a number of characters
#@string range [offset, len]
substr=${string:7:-2}
echo '${string:7:-2}'"=${substr}"


#@string range (offset, len]
substr=${string: -7:-2}
echo '${string:7:-2}'"=${substr}"

#expanded to name match the pattern
#${!prefix*}
#${!prefix@}
echo ${!s*} ${!s@}

#short   pattern ${parameter#word}
#longest pattern ${parameter##word}
#The word is expanded to produce a pattern
#If the pattern matches the beginning of the expanded value of parameter, then the
#result of the expansion is the expanded value of parameter with the shortest
#matching pattern (the ‘#’ case) or the longest matching pattern (the ‘##’ case) deleted.

#as for array and postional parameters
#If parameter is ‘@’ or ‘*’, the pattern removal operation is applied to
#each positional parameter in turn, and the expansion is the resultant list. If
#parameter is an array variable subscripted with ‘@’ or ‘*’, the pattern removal
#operation is applied to each member of the array in turn, and the expansion is
#the resultant list.
echo ${string#012}
echo ${@#z*sh}