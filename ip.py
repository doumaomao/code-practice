# -*- coding: utf-8 -*-
import sys, urllib, urllib2, json

url = 'http://apis.baidu.com/netpopo/ip/ip?ip=185.223.165.195&appkey=1307ee261de8bbcf83830de89caae73f'


req = urllib2.Request(url)

req.add_header("apikey", "xxxxx")

resp = urllib2.urlopen(req)
content = resp.read()
if(content):
    print(content)
