#! /usr/bin/python
#-*- coding:utf-8 -*-

sentence = "stay hungry, stay foolish"
sentence.startswith("#")
sentence.endswith("#")

sentence.lstrip()
sentence.rstrip()
sentence.strip()

line = '[convolutional]'
if line.startswith('['):
    section = line.strip().strip('[]')
    print(section)

