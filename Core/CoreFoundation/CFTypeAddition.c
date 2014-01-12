//
//  CFTypeAddition.c
//  Core
//
//  Created by Sam Marshall on 1/12/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef Core_CFTypeAddition_c
#define Core_CFTypeAddition_c

#include "CFTypeAddition.h"
#include "CFDictionaryAddition.h"
#include "Number.h"
#include <objc/NSObjCRuntime.h>

extern void PrintCFDictionaryInternalFormatting(CFDictionaryRef dictionary, uint32_t depth);

void PrintCFTypeInternalFormat(CFTypeRef value, uint32_t depth) {
	CFStringRef valueType = CFCopyTypeIDDescription(CFGetTypeID(value));
	if (CFStringCompare(valueType, CFCopyTypeIDDescription(CFDictionaryGetTypeID()), 0x0) == kCFCompareEqualTo) {
		printf("\n");
		PrintCFDictionaryInternalFormatting(value, depth+0x1);
		printf("\n");
	} else
	if (CFStringCompare(valueType, CFCopyTypeIDDescription(CFBooleanGetTypeID()), 0x0) == kCFCompareEqualTo) {
		printf("%s\n",(CFBooleanGetValue(value) ? "True" : "False"));
	} else
	if (CFStringCompare(valueType, CFCopyTypeIDDescription(CFStringGetTypeID()), 0x0) == kCFCompareEqualTo) {
		printf("%s\n",(char*)CFStringGetCStringPtr(value,kCFStringEncodingUTF8));
	} else
	if (CFStringCompare(valueType, CFCopyTypeIDDescription(CFNumberGetTypeID()), 0x0) == kCFCompareEqualTo) {
		CFIndex numberType = CFNumberGetType(value);
		switch (numberType) {
			case kCFNumberSInt8Type: {
				SInt8 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%hhd\n",number);
				break;
			};
			case kCFNumberSInt16Type: {
				SInt16 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%hd\n",number);
				break;
			};
			case kCFNumberSInt32Type: {
				SInt32 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%dz\n",number);
				break;
			};
			case kCFNumberSInt64Type: {
				SInt64 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%lldz\n",number);
				break;
			};
			case kCFNumberFloat32Type: {
				Float32 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			case kCFNumberFloat64Type: {
				Float64 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			case kCFNumberCharType: {
				char number;
				CFNumberGetValue(value, numberType, &number);
				printf("%c\n",number);
				break;
			};
			case kCFNumberShortType: {
				short number;
				CFNumberGetValue(value, numberType, &number);
				printf("%hd\n",number);
				break;
			};
			case kCFNumberIntType: {
				int number;
				CFNumberGetValue(value, numberType, &number);
				printf("%dz\n",number);
				break;
			};
			case kCFNumberLongType: {
				long number;
				CFNumberGetValue(value, numberType, &number);
				printf("%ldz\n",number);
				break;
			};
			case kCFNumberLongLongType: {
				long long number;
				CFNumberGetValue(value, numberType, &number);
				printf("%qdz\n",number);
				break;
			};
			case kCFNumberFloatType: {
				float number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			case kCFNumberDoubleType: {
				double number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			case kCFNumberCFIndexType: {
				CFIndex number;
				CFNumberGetValue(value, numberType, &number);
				printf("%ldz\n",number);
				break;
			};
			case kCFNumberNSIntegerType: {
				NSInteger number;
				CFNumberGetValue(value, numberType, &number);
				printf("%ldz\n",number);
				break;
			};
			case kCFNumberCGFloatType: {
				CGFloat number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			default: {
				break;
			};
		}
	} else {
		CFStringRef description = CFCopyDescription(value);
		printf("%s\n",(char*)CFStringGetCStringPtr(description,kCFStringEncodingUTF8));
	}
}

void PrintCFType(CFTypeRef value) {
	PrintCFTypeInternalFormat(value, 0x0);
}

#endif