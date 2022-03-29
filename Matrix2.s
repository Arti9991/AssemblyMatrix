#Умножение матриц
#Файл для умножения матриц Matrix.s*/

#Порядок регистров в вызываемой функции
# %rdi, %rsi, %rdx, %rcx, %r8, %r9

#вызываемая функция float* Matrix (float* a, float* b, float* c, int M, int N, int K);

.text
 .global Matrix
Matrix:

push %rbp 
push %rsp 
push %rbx 
push %r12 
push %r13 
push %r14 
push %r15 

mov $0, %r10
mov $0, %r11
mov $0, %r12
mov $0, %r13
mov $0, %r14
mov $0, %r15

  mov %rdx, %r11


  vmovups (%rdx), %ymm1

  lea (%rdx, %r8,4), %r13
  movq %r13, %rdx
  vmovups (%rdx), %ymm2

  lea (%rdx, %r8,4), %r13
  movq %r13, %rdx
  vmovups (%rdx), %ymm3

  lea (%rdx, %r8,4), %r13
  movq %r13, %rdx
  vmovups (%rdx), %ymm4

  lea (%rdx, %r8,4), %r13
  movq %r13, %rdx
  vmovups (%rdx), %ymm5

  lea (%rdx, %r8,4), %r13
  movq %r13, %rdx
  vmovups (%rdx), %ymm6

  lea (%rdx, %r8,4), %r13
  movq %r13, %rdx
  vmovups (%rdx), %ymm7

  lea (%rdx, %r8,4), %r13
  movq %r13, %rdx
  vmovups (%rdx), %ymm8

  mov %r11, %rdx
    
  B:
    vmovups (%rsi), %ymm9


    vbroadcastss (%rdi), %ymm0
    vfmadd231ps %ymm0, %ymm9, %ymm1
            
    vbroadcastss 4(%rdi), %ymm10
    vfmadd231ps %ymm10, %ymm9, %ymm2
          
    vbroadcastss 8(%rdi), %ymm11
    vfmadd231ps %ymm11, %ymm9, %ymm3
            
    vbroadcastss 12(%rdi), %ymm12
    vfmadd231ps %ymm12, %ymm9, %ymm4
            
    vbroadcastss 16(%rdi), %ymm13
    vfmadd231ps %ymm13, %ymm9, %ymm5
           
    vbroadcastss 20(%rdi), %ymm14
    vfmadd231ps %ymm14, %ymm9, %ymm6
            
    vbroadcastss 24(%rdi), %ymm15
    vfmadd231ps %ymm15, %ymm9, %ymm7

            
    vbroadcastss 28(%rdi), %ymm0
    vfmadd231ps %ymm0, %ymm9, %ymm8
            

    leaq (%rdi,%rcx,4), %r13  
    movq %r13, %rdi
          
    leaq (%rsi, %r8,4), %r13
    movq %r13, %rsi

    add $1, %r14
    cmp %r9, %r14
    jb  B
 
   
   
 vmovups %ymm1,  (%rdx)

 lea (%rdx, %r8, 4), %r13
 movq %r13, %rdx
 vmovups %ymm2,  (%rdx)

 lea (%rdx, %r8, 4), %r13
 movq %r13, %rdx
 vmovups %ymm3,  (%rdx)

 lea (%rdx, %r8, 4), %r13
 movq %r13, %rdx
 vmovups %ymm4,  (%rdx)

 lea (%rdx, %r8, 4), %r13
 movq %r13, %rdx
 vmovups %ymm5,  (%rdx)

 lea (%rdx, %r8, 4), %r13
 movq %r13, %rdx
 vmovups %ymm6,  (%rdx)

 lea (%rdx, %r8, 4), %r13
 movq %r13, %rdx
 vmovups %ymm7,  (%rdx)

 lea (%rdx, %r8, 4), %r13
 movq %r13, %rdx
 vmovups %ymm8,  (%rdx)


pop %r15 
pop %r14 
pop %r13 
pop %r12 
pop %rbx 
pop %rsp
pop %rbp 

ret

    



    
