comment(' Trisha Andres ')
comment(' CPSC 2310 - Section 001 ')
comment(' Program Assignment 1 ')
comment(' 05/29/2023 ')

comment(' This program will take in a binary integer and ')
comment(' output its decimal equivalent ')

	word(N, 1101)
	word(bit_position, 1)
	word(binary, 0)
	word(rem, 0)
	word(sum, 0)
	word(ten, 10)
	word(two, 2)

label(start)
	load(N)
	div(ten)
	store(binary)

	load(binary)
	mul(ten)
	store(binary)

	load(N)
	sub(binary)
	store(rem)
	ble0(done)

label(loop)

	load(N)
	div(ten)
	store(N)

	load(rem)
	mul(bit_position)
	store(rem)

	load(sum)
	add(rem)
	store(sum)

	load(bit_position)
	mul(two)
	store(bit_position)

	load(N)
	div(ten)
	store(binary)

	load(binary)
	mul(ten)
	store(binary)

	load(N)
	sub(binary)
	store(rem)

	load(N)
	bgt0(loop)

label(done)
	print(sum)
	halt

	end(start)
