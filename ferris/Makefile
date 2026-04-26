KEYBOARD = splitkb/halcyon/ferris/rev1
KEYMAP = artur

all:
	qmk compile \
		-kb $(KEYBOARD) \
		-km $(KEYMAP) \
	       	-e HLC_ENCODER=1 \
	       	-e TARGET=ferris_left_encoder
	qmk compile \
		-kb $(KEYBOARD) \
		-km $(KEYMAP) \
	       	-e HLC_CIRQUE_TRACKPAD=1 \
	       	-e TARGET=ferris_right_trackpad
