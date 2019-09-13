	.file	"chal.c"
	.intel_syntax noprefix
	.text
	.globl	ip
	.bss
	.align 4
	.type	ip, @object
	.size	ip, 4
ip:
	.zero	4
	.globl	sp
	.align 4
	.type	sp, @object
	.size	sp, 4
sp:
	.zero	4
	.globl	ax
	.align 4
	.type	ax, @object
	.size	ax, 4
ax:
	.zero	4
	.text
	.globl	vmstep
	.type	vmstep, @function
vmstep:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	eax, edi
	mov	QWORD PTR -16[rbp], rsi
	mov	BYTE PTR -4[rbp], al
	movzx	eax, BYTE PTR -4[rbp]
	or	eax, 32
	movsx	eax, al
	sub	eax, 32
	cmp	eax, 90
	ja	.L19
	mov	eax, eax
	lea	rdx, 0[0+rax*4]
	lea	rax, .L4[rip]
	mov	eax, DWORD PTR [rdx+rax]
	cdqe
	lea	rdx, .L4[rip]
	add	rax, rdx
	jmp	rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L12-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L15-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L14-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L13-.L4
	.long	.L12-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L11-.L4
	.long	.L10-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L9-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L8-.L4
	.long	.L19-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L19-.L4
	.long	.L5-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L19-.L4
	.long	.L3-.L4
	.text
.L15:
	movzx	eax, BYTE PTR -4[rbp]
	or	eax, 32
	movsx	eax, al
	sub	eax, 48
	mov	DWORD PTR ax[rip], eax
	jmp	.L16
.L14:
	mov	eax, DWORD PTR sp[rip]
	movsx	rdx, eax
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movsx	edx, al
	mov	eax, DWORD PTR ax[rip]
	add	eax, edx
	mov	DWORD PTR ax[rip], eax
	jmp	.L16
.L13:
	mov	eax, DWORD PTR ax[rip]
	sub	eax, 1
	mov	DWORD PTR ax[rip], eax
	jmp	.L16
.L12:
	mov	eax, 0
	jmp	.L17
.L11:
	mov	eax, DWORD PTR ax[rip]
	add	eax, 1
	mov	DWORD PTR ax[rip], eax
	jmp	.L16
.L10:
	mov	eax, DWORD PTR ax[rip]
	lea	edx, -1[rax]
	mov	eax, DWORD PTR ip[rip]
	add	eax, edx
	mov	DWORD PTR ip[rip], eax
	jmp	.L16
.L9:
	mov	eax, DWORD PTR sp[rip]
	movsx	rdx, eax
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movsx	edx, al
	mov	eax, DWORD PTR ax[rip]
	imul	eax, edx
	mov	DWORD PTR ax[rip], eax
	jmp	.L16
.L8:
	mov	eax, DWORD PTR sp[rip]
	movsx	rdx, eax
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	mov	edi, eax
	call	putchar@PLT
	jmp	.L16
.L7:
	mov	eax, DWORD PTR ax[rip]
	mov	DWORD PTR sp[rip], eax
	jmp	.L16
.L6:
	mov	edx, DWORD PTR ax[rip]
	mov	eax, DWORD PTR sp[rip]
	movsx	rcx, eax
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rcx
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	sub	edx, eax
	mov	eax, edx
	mov	DWORD PTR ax[rip], eax
	jmp	.L16
.L5:
	mov	ecx, DWORD PTR ax[rip]
	mov	eax, DWORD PTR sp[rip]
	movsx	rdx, eax
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	mov	edx, ecx
	mov	BYTE PTR [rax], dl
	jmp	.L16
.L3:
	mov	eax, DWORD PTR sp[rip]
	movsx	rdx, eax
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	test	al, al
	jne	.L20
	mov	eax, DWORD PTR ax[rip]
	lea	edx, -1[rax]
	mov	eax, DWORD PTR ip[rip]
	add	eax, edx
	mov	DWORD PTR ip[rip], eax
	jmp	.L20
.L19:
	nop
	jmp	.L16
.L20:
	nop
.L16:
	mov	eax, 1
.L17:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	vmstep, .-vmstep
	.globl	vmexec
	.type	vmexec, @function
vmexec:
.LFB1:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	mov	QWORD PTR -16[rbp], rsi
	mov	DWORD PTR ip[rip], 0
.L24:
	mov	eax, DWORD PTR ip[rip]
	movsx	rdx, eax
	mov	rax, QWORD PTR -8[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	mov	rdx, QWORD PTR -16[rbp]
	mov	rsi, rdx
	mov	edi, eax
	call	vmstep
	test	eax, eax
	je	.L26
	mov	eax, DWORD PTR ip[rip]
	add	eax, 1
	mov	DWORD PTR ip[rip], eax
	jmp	.L24
.L26:
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	vmexec, .-vmexec
	.section	.rodata
.LC1:
	.string	"%1337s"
	.align 8
.LC0:
	.ascii	"0r2u6mmr2u6mmimmiu0r2u5mimir2u5mmmu0r2u5mimr2u4mmmiu0r2u5mmi"
	.ascii	"r2u5mmmimiu0r2u5mmr2u4mimmiu0r2u4mimir2u7mimu0r2u4mimr2u6"
	.string	"mmmmu0r2u4mmir2u4mimimimu0r2u4mmr2u5mimimimu0r2u7mir2u6mmimimu0r2u7mr2u5mimmmu0r2u6mir2u5mmmimu0r2u6mr2u5mmmiu0r2u5mir2u4mimimu0r2u5mr2u5mmimmiu9r2u5mmimu8r2u6mimmimu7r2u5mimmmu6r2u6mmimimiu5r2u7mmmmiu4r2u7mmimimiu3r2u5mmmmu2r2u5mmmimu1r2u4mmmmu0r2u4mimmmu"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 2448
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	mov	QWORD PTR -2352[rbp], 0
	mov	QWORD PTR -2344[rbp], 0
	mov	QWORD PTR -2336[rbp], 0
	mov	QWORD PTR -2328[rbp], 0
	mov	QWORD PTR -2320[rbp], 0
	mov	QWORD PTR -2312[rbp], 0
	mov	QWORD PTR -2304[rbp], 0
	mov	QWORD PTR -2296[rbp], 0
	mov	QWORD PTR -2288[rbp], 0
	mov	QWORD PTR -2280[rbp], 0
	mov	QWORD PTR -2272[rbp], 0
	mov	QWORD PTR -2264[rbp], 0
	mov	DWORD PTR -2256[rbp], 0
	mov	BYTE PTR -2252[rbp], 0
	mov	QWORD PTR -2240[rbp], 0
	mov	QWORD PTR -2232[rbp], 0
	mov	QWORD PTR -2224[rbp], 0
	mov	QWORD PTR -2216[rbp], 0
	mov	QWORD PTR -2208[rbp], 0
	mov	QWORD PTR -2200[rbp], 0
	mov	QWORD PTR -2192[rbp], 0
	mov	QWORD PTR -2184[rbp], 0
	mov	QWORD PTR -2176[rbp], 0
	mov	QWORD PTR -2168[rbp], 0
	mov	QWORD PTR -2160[rbp], 0
	mov	QWORD PTR -2152[rbp], 0
	mov	DWORD PTR -2144[rbp], 0
	mov	BYTE PTR -2140[rbp], 0
	mov	QWORD PTR -1360[rbp], 0
	mov	QWORD PTR -1352[rbp], 0
	lea	rdx, -1344[rbp]
	mov	eax, 0
	mov	ecx, 165
	mov	rdi, rdx
	rep stosq
	mov	rdx, rdi
	mov	BYTE PTR [rdx], al
	add	rdx, 1
	movabs	rax, 7885074441300112690
	movabs	rdx, 7596788023429199209
	mov	QWORD PTR -1888[rbp], rax
	mov	QWORD PTR -1880[rbp], rdx
	movabs	rax, 3634534012068653421
	movabs	rdx, 8461539574473897845
	mov	QWORD PTR -1872[rbp], rax
	mov	QWORD PTR -1864[rbp], rdx
	movabs	rax, 7883952938521277040
	movabs	rdx, 7869887733348788589
	mov	QWORD PTR -1856[rbp], rax
	mov	QWORD PTR -1848[rbp], rdx
	movabs	rsi, 8444935900922211693
	movabs	rdi, 8444935900922473780
	mov	QWORD PTR -1840[rbp], rsi
	mov	QWORD PTR -1832[rbp], rdi
	movabs	rsi, 8103503421210717495
	movabs	rdi, 7885078822166885682
	mov	QWORD PTR -1824[rbp], rsi
	mov	QWORD PTR -1816[rbp], rdi
	movabs	rsi, 7596848227105796213
	movabs	rdi, 3779982920834968941
	mov	QWORD PTR -1808[rbp], rsi
	mov	QWORD PTR -1800[rbp], rdi
	movabs	rsi, 3924098108911086957
	movabs	rdi, 8460413674567068013
	mov	QWORD PTR -1792[rbp], rsi
	mov	QWORD PTR -1784[rbp], rdi
	mov	QWORD PTR -1776[rbp], rax
	mov	QWORD PTR -1768[rbp], rdx
	movabs	rax, 3634533994955894121
	mov	QWORD PTR -1760[rbp], rax
	mov	DWORD PTR -1752[rbp], 1970091381
	mov	WORD PTR -1748[rbp], 112
	movabs	rax, 7596844065148466482
	movabs	rdx, 7885018399580910957
	mov	QWORD PTR -2128[rbp], rax
	mov	QWORD PTR -2120[rbp], rdx
	movabs	rax, 8444935900855364969
	movabs	rdx, 8103503404097957175
	mov	QWORD PTR -2112[rbp], rax
	mov	QWORD PTR -2104[rbp], rdx
	movabs	rax, 7885078822166885682
	movabs	rdx, 7885018399580910953
	mov	QWORD PTR -2096[rbp], rax
	mov	QWORD PTR -2088[rbp], rdx
	movabs	rax, 8444935900922211689
	movabs	rdx, 8460413691746676023
	mov	QWORD PTR -2080[rbp], rax
	mov	QWORD PTR -2072[rbp], rdx
	movabs	rax, 7885074440381608560
	movabs	rdx, 7869606258372077933
	mov	QWORD PTR -2064[rbp], rax
	mov	QWORD PTR -2056[rbp], rdx
	movabs	rax, 8103503404097695081
	movabs	rdx, 7596844065148532018
	mov	QWORD PTR -2048[rbp], rax
	mov	QWORD PTR -2040[rbp], rdx
	movabs	rax, 7869324783395367277
	mov	QWORD PTR -2032[rbp], rax
	mov	WORD PTR -2024[rbp], 28789
	mov	BYTE PTR -2022[rbp], 0
	lea	rax, -1744[rbp]
	lea	rdx, .LC0[rip]
	mov	ecx, 46
	mov	rdi, rax
	mov	rsi, rdx
	rep movsq
	mov	rdx, rsi
	mov	rax, rdi
	mov	ecx, DWORD PTR [rdx]
	mov	DWORD PTR [rax], ecx
	lea	rax, 4[rax]
	lea	rdx, 4[rdx]
	movzx	ecx, WORD PTR [rdx]
	mov	WORD PTR [rax], cx
	lea	rax, 2[rax]
	lea	rdx, 2[rdx]
	movabs	rax, 7596844065148466482
	movabs	rdx, 7869887733348788589
	mov	QWORD PTR -2016[rbp], rax
	mov	QWORD PTR -2008[rbp], rdx
	movabs	rax, 8444935900922211693
	movabs	rdx, 7883952922263383350
	mov	QWORD PTR -2000[rbp], rax
	mov	QWORD PTR -1992[rbp], rdx
	movabs	rax, 7596788023429199209
	movabs	rdx, 3634534012068653421
	mov	QWORD PTR -1984[rbp], rax
	mov	QWORD PTR -1976[rbp], rdx
	movabs	rax, 7883952922263631477
	movabs	rdx, 7885016200557655401
	mov	QWORD PTR -1968[rbp], rax
	mov	QWORD PTR -1960[rbp], rdx
	movabs	rax, 7596788023429199213
	movabs	rdx, 3634533994955631981
	mov	QWORD PTR -1952[rbp], rax
	mov	QWORD PTR -1944[rbp], rdx
	movabs	rax, 7596848446018762357
	movabs	rdx, 7883952707645632629
	mov	QWORD PTR -1936[rbp], rax
	mov	QWORD PTR -1928[rbp], rdx
	movabs	rax, 3779982920834968941
	movabs	rdx, 8444935900855364973
	mov	QWORD PTR -1920[rbp], rax
	mov	QWORD PTR -1912[rbp], rdx
	mov	DWORD PTR -1904[rbp], 1886743861
	mov	BYTE PTR -1900[rbp], 0
	movabs	rax, 7596844065148400946
	movabs	rdx, 7596788023429199213
	mov	QWORD PTR -2432[rbp], rax
	mov	QWORD PTR -2424[rbp], rdx
	movabs	rax, 8444935900922472813
	movabs	rdx, 8103499023231315254
	mov	QWORD PTR -2416[rbp], rax
	mov	QWORD PTR -2408[rbp], rdx
	movabs	rax, 7596844065148532018
	movabs	rdx, 7869043308418656621
	mov	QWORD PTR -2400[rbp], rax
	mov	QWORD PTR -2392[rbp], rdx
	movabs	rax, 7869887733348789613
	movabs	rdx, 3779982920835230061
	mov	QWORD PTR -2384[rbp], rax
	mov	QWORD PTR -2376[rbp], rdx
	mov	DWORD PTR -2368[rbp], 1970105709
	mov	WORD PTR -2364[rbp], 112
	lea	rdx, -2240[rbp]
	lea	rax, -1888[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	vmexec
	lea	rax, -1360[rbp]
	mov	rsi, rax
	lea	rdi, .LC1[rip]
	mov	eax, 0
	call	__isoc99_scanf@PLT
	lea	rdx, -2240[rbp]
	lea	rax, -2128[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	vmexec
	lea	rdx, -2352[rbp]
	lea	rax, -1360[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	vmexec
	lea	rdx, -2240[rbp]
	lea	rax, -1744[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	vmexec
	mov	DWORD PTR -2436[rbp], 0
	jmp	.L28
.L32:
	mov	eax, DWORD PTR -2436[rbp]
	cdqe
	movzx	eax, BYTE PTR -2352[rbp+rax]
	test	al, al
	jne	.L29
	mov	eax, DWORD PTR -2436[rbp]
	cdqe
	movzx	eax, BYTE PTR -2240[rbp+rax]
	test	al, al
	jne	.L29
	mov	DWORD PTR -2436[rbp], -1
	jmp	.L30
.L29:
	mov	eax, DWORD PTR -2436[rbp]
	cdqe
	movzx	eax, BYTE PTR -2352[rbp+rax]
	movsx	edx, al
	mov	eax, DWORD PTR -2436[rbp]
	cdqe
	movzx	eax, BYTE PTR -2240[rbp+rax]
	movsx	ecx, al
	mov	eax, DWORD PTR -2436[rbp]
	add	eax, ecx
	cmp	edx, eax
	jne	.L37
	add	DWORD PTR -2436[rbp], 1
.L28:
	cmp	DWORD PTR -2436[rbp], 99
	jle	.L32
	jmp	.L30
.L37:
	nop
.L30:
	cmp	DWORD PTR -2436[rbp], -1
	je	.L33
	lea	rdx, -2240[rbp]
	lea	rax, -2016[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	vmexec
	mov	eax, 0
	jmp	.L35
.L33:
	lea	rdx, -2240[rbp]
	lea	rax, -2432[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	vmexec
	lea	rax, -2352[rbp]
	mov	rdi, rax
	call	puts@PLT
	mov	eax, 0
.L35:
	mov	rcx, QWORD PTR -8[rbp]
	xor	rcx, QWORD PTR fs:40
	je	.L36
	call	__stack_chk_fail@PLT
.L36:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
