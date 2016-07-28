.name "marvin"
.comment "champion maniaco-depressif"
.extend

start:		zjmp	%:start
                zjmp	%:start
                zjmp	%:start
                zjmp	%:start
                zjmp	%:start
                zjmp	%:start
                zjmp	%:start

main:		sti	r1,%:live,%1
		sti	r1,%:lwall,%1
		sti	r1,%:rwall,%1
		sti	r1,%:copy,%1
		fork	%:iattack
		fork	%:irwall


live:		live	%42
		zjmp	%:live

iwall:		ld	%4,r2
		fork	%:iwall
wall:		ld	%0,r3

lwall:		live	%42
		sti	r1,%:start,r3
		sub	r3,r2,r3,r2,r3
		sti	r1,%:start,r3
		sub	r3,r2,r3
		sti	r1,%:start,r3
		sub	r3,r2,r3
		sti	r1,%:start,r3
		sub	r3,r2,r3
		sti	r1,%:start,r3
		sub	r3,r2,r3
		sti	r1,%:start,r3
		sub	r3,r2,r3
		xor	r3,%-360,r6
		zjmp	%:wall
		ld	%0,r6
		zjmp	%:lwall

irwall:		ld	%40,r4
		ld	%1,r5
rwall:		live	%42
		sub	r4,r5,r4
		fork	%:iwall
		xor	r4,%0,r4
		zjmp	%:end
		ld	%0,r6
		zjmp	%:rwall

iattack:	sti	r1,%:biglive1,%1
		sti	r1,%:biglive1,%6
		sti	r1,%:biglive1,%11
		sti	r1,%:biglive1,%16
		sti	r1,%:biglive1,%21
		sti	r1,%:biglive1,%26
		sti	r1,%:biglive1,%31
		sti	r1,%:biglive1,%36
		sti	r1,%:biglive1,%41
		sti	r1,%:biglive1,%46
		sti	r1,%:biglive2,%1
		sti	r1,%:biglive2,%6
		sti	r1,%:biglive2,%11
		sti	r1,%:biglive2,%16
		sti	r1,%:biglive2,%21
		sti	r1,%:biglive2,%26
		sti	r1,%:biglive2,%31
		sti	r1,%:biglive2,%36
		sti	r1,%:biglive2,%41
		sti	r1,%:biglive2,%46
		ld	%0,r6

icopy:		ld	%4,r2
		ld	%0,r3
		fork	%:biglive1
copy:		live	%42
		ldi	%:icopy,r3,r4
		sti	r4,%:end,r3
		add	r3,r2,r3
		xor	r3,%164,r6
		zjmp	%:end
		ld	%0,r6
		zjmp	%:copy

biglive1:	live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42

biglive2:	live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%:biglive1
end: