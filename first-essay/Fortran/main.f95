program main
    implicit none

    character(len=32) :: arg
    integer :: size
    integer :: i, j
    real(8), dimension(:,:), allocatable :: matrix
    real(8), dimension (:), allocatable :: vector
    real(8), dimension (:), allocatable :: result
    real(8) :: start, finish

    call GET_COMMAND_ARGUMENT(1, arg)
    read(arg, "(I10)") size

    allocate(matrix(size, size))
    allocate(vector(size))

    allocate(result(size))
    result = 0.0

    call random_seed()

    call generateRandomVector(size, vector)
    call generateRandomSquaredMatrix(size, matrix)

    call cpu_time(start)
    do i = 1, size
        do j = 1, size
            result(i) = result(i) +  matrix(i, j) * vector(j);
        end do
    end do
    call cpu_time(finish)

    print *, "Product iterating first through matrix lines took (in seconds):", (finish - start)

    result = 0.0

    call cpu_time(start)

    do j = 1, size
        do i = 1, size
            result(i) = result(i) +  matrix(i, j) * vector(j);
        end do
    end do

    call cpu_time(finish)

    print *, "Product iterating first through matrix columns took (in seconds):", (finish - start)

    contains

    subroutine generateRandomVector(size, vector)
        implicit none

        real(8), dimension(size) :: vector
        real(8) :: number
        integer :: i, size

        do i = 1, size
            call random_number(number)
            vector(i) = number
        end do
    end

    subroutine generateRandomSquaredMatrix(size, matrix)
        implicit none

        real(8), dimension(:, :) :: matrix
        real(8) :: number
        integer :: i, j, size

        do i = 1, size
            do j = 1, size
                call random_number(number)
                matrix(i, j) = number
            end do
        end do
    end
end program main