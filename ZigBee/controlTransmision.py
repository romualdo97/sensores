#!/usr/bin/python3
import serial
import time
import math
from xbee import XBee, ZigBee
from msvcrt import getch

serial_port = serial.Serial('COM6', 9600)

def print_data(data):
	"""
	This method is called whenever data is received
	from the associated XBee device. Its first and
	only argument is the data contained within the
	frame.
	"""
	#print(data)

xbee = ZigBee(serial_port, escaped = True, callback = print_data)
counter = 0

# https://stackoverflow.com/questions/12175964/python-method-for-reading-keypress
while True:
	time.sleep(0.2) # in seconds

	key = ord(getch())
	print(key)

	if key == 119: #w
		print('w')
		payload = 'F'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 115: #s
		print('s')
		payload = 'B'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 100: #d
		print('d')
		payload = 'R'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 97: #a
		print('a')
		payload = 'L'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 32: #stop
		print('[space]')
		payload = 'S'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 53: #numpad 5
		print('5')
		payload = '5'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 52: #numpad 4
		print('4')
		payload = '4'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 51: #numpad 3
		print('3')
		payload = '3'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 50: #numpad 2
		print('2')
		payload = '2'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)
	elif key == 49: #numpad 1
		print('1')
		payload = '1'
		xbee.send('tx', frame_id=b'A', dest_addr_long=b'\x00\x13\xA2\x00\x40\x52\xDA\xBF', data=payload)


xbee.halt()
serial_port.close()

