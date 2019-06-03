	ifndef	??version
?debug	macro
	endm
$comm	macro	name,dist,size,count
	comm	dist name:BYTE:count*size
	endm
	else
$comm	macro	name,dist,size,count
	comm	dist name[size]:BYTE:count
	endm
	endif
	?debug	S "swap.cpp"
	?debug	C E92E4F7A4E08737761702E637070
	?debug	C E90664704E12783A5C696E636C7564655C737464696F2E68
	?debug	C E90018521812783A5C696E636C7564655C5F646566732E68
	?debug	C E90018521812783A5C696E636C7564655C5F6E756C6C2E68
	?debug	C E90018521812783A5C696E636C7564655C636F6E696F2E68
_TEXT	segment byte public 'CODE'
_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
_TEXT	segment byte public 'CODE'
   ;	
   ;	swap(int inp1,int inp2)
   ;	
	assume	cs:_TEXT
@swap$qii	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	   int temp ;
   ;	   temp = inp1;
   ;	
	mov	ax,word ptr [bp+4]
	mov	word ptr [bp-2],ax
   ;	
   ;	   inp1= inp2 ;
   ;	
	mov	ax,word ptr [bp+6]
	mov	word ptr [bp+4],ax
   ;	
   ;	   inp2 =temp;
   ;	
	mov	ax,word ptr [bp-2]
	mov	word ptr [bp+6],ax
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
@swap$qii	endp
   ;	
   ;	swapByRef(int *inp1,int * inp2)
   ;	
	assume	cs:_TEXT
@swapByRef$qpit1	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	   int temp ;
   ;	   temp = *inp1;
   ;	
	mov	bx,word ptr [bp+4]
	mov	ax,word ptr [bx]
	mov	word ptr [bp-2],ax
   ;	
   ;	   *inp1= *inp2 ;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	mov	bx,word ptr [bp+4]
	mov	word ptr [bx],ax
   ;	
   ;	   *inp2 =temp;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bp-2]
	mov	word ptr [bx],ax
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
@swapByRef$qpit1	endp
   ;	
   ;	swap_REF_VAR(int &inp1,int &inp2)
   ;	
	assume	cs:_TEXT
@swap_REF_VAR$qrit1	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
   ;	
   ;	{
   ;	   int temp ;
   ;	   temp = inp1;
   ;	
	mov	bx,word ptr [bp+4]
	mov	ax,word ptr [bx]
	mov	word ptr [bp-2],ax
   ;	
   ;	   inp1= inp2 ;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bx]
	mov	bx,word ptr [bp+4]
	mov	word ptr [bx],ax
   ;	
   ;	   inp2 =temp;
   ;	
	mov	bx,word ptr [bp+6]
	mov	ax,word ptr [bp-2]
	mov	word ptr [bx],ax
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
@swap_REF_VAR$qrit1	endp
   ;	
   ;	int main()
   ;	
	assume	cs:_TEXT
_main	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
   ;	
   ;	{
   ;	 int num1=10,num2=20;
   ;	
	mov	word ptr [bp-2],10
	mov	word ptr [bp-4],20
   ;	
   ;	 clrscr();
   ;	
	call	near ptr _clrscr
   ;	
   ;	 printf("Values before Swapping num1 : %d  num2 : %d\n",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	 swap(num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	call	near ptr @swap$qii
	pop	cx
	pop	cx
   ;	
   ;	 printf("Values after Swapping num1 : %d  num2 : %d\n",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+45
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	 printf("Values before Swapping by REF num1 : %d  num2 : %d\n",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+89
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	 swapByRef(&num1,&num2);
   ;	
	lea	ax,word ptr [bp-4]
	push	ax
	lea	ax,word ptr [bp-2]
	push	ax
	call	near ptr @swapByRef$qpit1
	pop	cx
	pop	cx
   ;	
   ;	 printf("Values after Swapping by REF num1 : %d  num2 : %d\n",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+141
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	 printf("Values before Swapping by REF VAR num1 : %d  num2 : %d\n",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+192
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	 swap_REF_VAR(num1,num2);
   ;	
	lea	ax,word ptr [bp-4]
	push	ax
	lea	ax,word ptr [bp-2]
	push	ax
	call	near ptr @swap_REF_VAR$qrit1
	pop	cx
	pop	cx
   ;	
   ;	 printf("Values after Swapping by REF VAR num1 : %d  num2 : %d\n",num1,num2);
   ;	
	push	word ptr [bp-4]
	push	word ptr [bp-2]
	mov	ax,offset DGROUP:s@+248
	push	ax
	call	near ptr _printf
	add	sp,6
   ;	
   ;	
   ;	
   ;	 getch();
   ;	
	call	near ptr _getch
   ;	
   ;	 return 0 ;
   ;	
	xor	ax,ax
	jmp	short @4@58
@4@58:
   ;	
   ;	}
   ;	
	mov	sp,bp
	pop	bp
	ret	
_main	endp
	?debug	C E9
_TEXT	ends
_DATA	segment word public 'DATA'
s@	label	byte
	db	'Values before Swapping num1 : %d  num2 : %d'
	db	10
	db	0
	db	'Values after Swapping num1 : %d  num2 : %d'
	db	10
	db	0
	db	'Values before Swapping by REF num1 : %d  num2 : %d'
	db	10
	db	0
	db	'Values after Swapping by REF num1 : %d  num2 : %d'
	db	10
	db	0
	db	'Values before Swapping by REF VAR num1 : %d  num2 : %d'
	db	10
	db	0
	db	'Values after Swapping by REF VAR num1 : %d  num2 : %d'
	db	10
	db	0
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	public	_main
	public	@swap_REF_VAR$qrit1
	public	@swapByRef$qpit1
	public	@swap$qii
	extrn	_getch:near
	extrn	_clrscr:near
	extrn	_printf:near
_s@	equ	s@
	end
