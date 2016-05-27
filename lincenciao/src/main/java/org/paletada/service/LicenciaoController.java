package org.paletada.service;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;

import org.influxdb.InfluxDB;
import org.influxdb.InfluxDBFactory;
import org.influxdb.dto.Point;
import org.paletada.message.Message;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

public class LicenciaoController {
	
	 

	    @RequestMapping("/berrear")
	    public Message greeting(@RequestParam(value="name", defaultValue="World") String name) {
	    	
	    	InfluxDB influxDB = InfluxDBFactory.connect("http://172.17.0.2:8086", "root", "root");
	    	String dbName = "aTimeSeries";
	    	influxDB.createDatabase(dbName);

	    	// Flush every 2000 Points, at least every 100ms
	    	influxDB.enableBatch(2000, 100, TimeUnit.MILLISECONDS);

	    	Point point1 = Point.measurement("cpu")
	    	                    .time(System.currentTimeMillis(), TimeUnit.MILLISECONDS)
	    	                    .addField("idle", 90L)
	    	                    .addField("user", 9L)
	    	                    .addField("system", 1L)
	    	                    .build();
	    	
	    	

	    	influxDB.write(dbName, "default", point1);
	        return new Message();
	    }

}
