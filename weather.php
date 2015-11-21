<?php
/**
 * Created by PhpStorm.
 * User: test
 * Date: 2015/11/19
 * Time: 17:10
 */

$ch = curl_init();
$url = 'http://apis.baidu.com/heweather/weather/free?city=beijing';
$header = array(
    'apikey:xxxxxxx',
);

//添加apikey到header
curl_setopt($ch, CURLOPT_HTTPHEADER, $header);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

//执行http请求
curl_setopt($ch, CURLOPT_URL, $url);
$res = curl_exec($ch);
var_dump(json_decode($res, 1));

//字段处理即可