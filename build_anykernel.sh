#!/bin/bash

version="$(make O=out kernelversion | grep -v make)"
echo "Kernel Version is ${version}"
echo ""

if [[ ! -e releases ]]; then
	mkdir releases
fi

cp out/arch/arm64/boot/Image.gz-dtb anykernel3/
cd anykernel3
zip -r9 nethunter-TNOKernel-v$version.zip * -x .git README.md *placeholder
mv nethunter-TNOKernel-v$version.zip ../releases
rm Image.gz-dtb
