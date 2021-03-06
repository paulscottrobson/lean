from PIL import Image

palette = [[255, 255, 255], [136, 0, 0], [170, 255, 238], [204, 68, 204], [0, 204, 85], [0, 0, 170], [238, 238, 119], [221, 136, 85], [102, 68, 0], [255, 119, 119], [51, 51, 51], [119, 119, 119], [170, 255, 102], [0, 136, 255], [187, 187, 187]]
im = Image.open("mario.png")
spriteData = [ 0 ] * (64*32+2)
for x in range(0,64):
	for y in range(0,64):
		rgba = im.getpixel((x,y))
		if rgba[3] != 0:
			best = 999999
			for i in range(0,len(palette)):
				score = pow(palette[i][0]-rgba[0],2)+pow(palette[i][1]-rgba[1],2)+pow(palette[i][2]-rgba[2],2)
				if score < best:
					col = i+1
					best = score
			spriteData[y*32+(x>>1)] += (col if x%2 != 0 else (col << 4))
print(max(spriteData))
h = open("SPRITES.BIN","wb")
h.write(bytearray(spriteData))
h.close()