﻿; Listing generated by Microsoft (R) Optimizing Compiler Version 16.00.30319.01 

	TITLE	E:\program\SimSystem\DataProcess\ClientDll\UploadDataToServer\UploadDataToServer\dllmain.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	_DllMain@12
EXTRN	__RTC_Shutdown:PROC
EXTRN	__RTC_InitBase:PROC
;	COMDAT rtc$TMZ
; File e:\program\simsystem\dataprocess\clientdll\uploaddatatoserver\uploaddatatoserver\dllmain.cpp
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
; Function compile flags: /Odtp /RTCsu /ZI
rtc$IMZ	ENDS
;	COMDAT _DllMain@12
_TEXT	SEGMENT
tv64 = -196						; size = 4
_hModule$ = 8						; size = 4
_ul_reason_for_call$ = 12				; size = 4
_lpReserved$ = 16					; size = 4
_DllMain@12 PROC					; COMDAT
; Line 8
	push	ebp
	mov	ebp, esp
	sub	esp, 196				; 000000c4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-196]
	mov	ecx, 49					; 00000031H
	mov	eax, -858993460				; ccccccccH
	rep stosd
; Line 9
	mov	eax, DWORD PTR _ul_reason_for_call$[ebp]
	mov	DWORD PTR tv64[ebp], eax
; Line 17
	mov	eax, 1
; Line 18
	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	12					; 0000000cH
_DllMain@12 ENDP
_TEXT	ENDS
END
