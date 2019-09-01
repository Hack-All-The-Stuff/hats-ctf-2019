import lief
import sys

binary = lief.parse(sys.argv[1])
for segment in binary.segments:
    if segment.has(".data"):
        segment.add(lief.ELF.SEGMENT_FLAGS.X)
    if segment.has(".bss"):
        segment.add(lief.ELF.SEGMENT_FLAGS.X)
    if segment.has(".text"):
        segment.add(lief.ELF.SEGMENT_FLAGS.W)
binary.write(sys.argv[1])