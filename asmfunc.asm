section .data
scalar: dd 255.0                     ; Constant value 255.0 as single precision float
section .text
bits 64
default rel
global imgCvtGrayInttoFloat

imgCvtGrayInttoFloat:
    ; Parameters:
    ; RCX: intImage (input array pointer)
    ; RDX: floatImage (output array pointer)
    ; R8: height
    ; R9: width

    ; Constants
    movss xmm1, dword [rel scalar]   ; Load 255.0 into xmm1

    ; Compute total number of pixels (height * width)
    imul r8, r9                     ; R8 = height * width (total pixels)

.loop:
    test r8, r8                      ; Check if r8 == 0
    jz .done                         ; Exit loop if finished

    ; Convert int to float
    mov eax, [rcx]                   ; Load current int pixel value (from intImage)
    cvtsi2ss xmm0, eax               ; Convert int to float

    ; Scale float value (x / 255.0)
    divss xmm0, xmm1                 ; Divide xmm0 by 255.0

    ; Store the result
    movss [rdx], xmm0                ; Store the float pixel value (into floatImage)

    ; Advance pointers
    add rcx, 4                       ; Move to the next int pixel
    add rdx, 4                       ; Move to the next float pixel

    dec r8                           ; Decrement pixel counter (total pixels)
    jmp .loop                         ; Repeat for next pixel

.done:
    ret                              ; Return to C

