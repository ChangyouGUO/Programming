#! /usr/bin/python
#-*- coding:utf-8 -*-

import configparser
import os
import io
from collections import defaultdict

def unique_config_sections(config_file):
    """Convert all config sections to have unique names.

    Adds unique suffixes to config sections for compability with configparser.
    """
    section_counters = defaultdict(int)
    output_stream = io.StringIO()
    with open(config_file) as fin:
        for line in fin:
            if line.startswith('['):
                section = line.strip().strip('[]')
                _section = section + '_' + str(section_counters[section])
                section_counters[section] += 1
                line = line.replace(section, _section)
            output_stream.write(line)
    output_stream.seek(0)
    return output_stream

config_path = os.path.dirname(os.path.abspath(__file__))
config_file = os.path.join(config_path, "yolov3.cfg")
print('Parsing Darknet config: {}'.format(config_file))

unique_config_file = unique_config_sections(config_file)
cfg_parser = configparser.ConfigParser()
cfg_parser.read_file(unique_config_file)
print(cfg_parser.sections())