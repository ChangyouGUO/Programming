import base64

# 感觉编码和图片都需要放在文件里，感觉不如用图片
f = open('../../DataStructure/pictures/Morris.png', 'rb')
ls_f=base64.b64encode(f.read())
f.close()
print(ls_f)