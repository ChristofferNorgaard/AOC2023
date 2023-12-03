program A01
        implicit none
        
        integer :: num_args, i, cur, comb, status, pos, j
        character(len=100) :: arg
        character :: digits(10)
        character(10), dimension(10) :: words
        character(len=100) :: line
       
        integer :: first, last
        
        digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'] 
        comb = 0
        
        words(1) = "zero"
        words(2) = "one"
        words(3) = "two"
        words(4) = "three"
        words(5) = "four"
        words(6) = "five"
        words(7) = "six"
        words(8) = "seven"
        words(9) = "eight"
        words(10) = "nine"

        num_args = COMMAND_ARGUMENT_COUNT()
        call GET_COMMAND_ARGUMENT(1, arg) 
        open(unit=10, file=arg, status="old", action="read")
        do
                first = -1
                last = -1
                read(10, '(A)', iostat=status) line
                if(status < 0) exit 
                if(status > 0) then
                        write(*,*) "Error reading file"
                        stop
                end if
                print *, line
                do i = 1, len(line)
                        if(any(line(i:i) == digits)) then 
                                read(line(i:i), '(I1)') cur
                                if(first == -1) then
                                        first = cur 
                                end if
                                last = cur
                        end if
                        do j = 1, len(words)
                                pos = INDEX(line(i:), TRIM(words(j))) 
                                if(pos == 1) then
                                        if(first == -1) then
                                                first = j - 1 
                                        end if
                                        last = j - 1
                                end if
                        end do
                end do
                print *, first*10 + last
                comb = comb + first*10 + last
        end do
        close(10)
        
        print *, comb
end program A01
