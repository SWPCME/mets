default:
	mkdir -p isodir/boot/grub
	cp myos.bin isodir/boot/myos.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir

check:
	$(if grub-file --is-x86-multiboot myos.bin; then \
	  echo multiboot confirmed \
	else \
	  echo the file is not multiboot \
	fi)

run:
	qemu-system-x86_64 -cdrom myos.iso

iso:
	sudo dd if=myos.iso of=${DISK} && sync
