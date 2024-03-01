DROP DATABASE IF EXISTS Insurance;
CREATE DATABASE Insurance;
USE Insurance;

DROP TABLE IF EXISTS `HomeInsurance`;
DROP TABLE IF EXISTS `AutoInsurance`;
DROP TABLE IF EXISTS `HealthInsurance`;
DROP TABLE IF EXISTS `LifeInsurance`;
DROP TABLE IF EXISTS `ClientInfo`;

CREATE TABLE ClientInfo (
 
	 SSN INTEGER(11),  
     FirstName VARCHAR(25),
     LastName VARCHAR(25),  
     PhoneNumber VARCHAR(12),
     Addressline1 VARCHAR(50),
     Addressline2 VARCHAR(50),
     ZipCode VARCHAR(5),
     City VARCHAR(25),
     State VARCHAR(2),
     Birthday DATE,
	 PRIMARY KEY (SSN)
);

INSERT INTO ClientInfo (SSN, FirstName, LastName, PhoneNumber, AddressLine1, AddressLine2, ZipCode, City, State, Birthday) VALUES (123456789, 'Tim', 'Drake', '850-121-1333','royale road','light lane','32307', 'Tallahassee', 'FL', '1994-02-17'); 
INSERT INTO ClientInfo (SSN, FirstName, LastName, PhoneNumber, AddressLine1, AddressLine2, ZipCode, City, State, Birthday) VALUES (448611224, 'Jane', 'Lee', '800-299-5189','crescent fall','silver streak','27389', 'Washington', 'MD', '1987-05-24'); 
INSERT INTO ClientInfo (SSN, FirstName, LastName, PhoneNumber, AddressLine1, AddressLine2, ZipCode, City, State, Birthday) VALUES (996135628, 'Sam', 'Heartline', '404-204-9831','gold lane','sundrop','12084', 'Austin', 'TX', '1970-08-04'); 
INSERT INTO ClientInfo (SSN, FirstName, LastName, PhoneNumber, AddressLine1, AddressLine2, ZipCode, City, State, Birthday) VALUES (641889133, 'Joseph', 'Beck', '350-267-4341','Moley heights','farview','29301', 'Nashville', 'TN', '2000-11-13'); 
INSERT INTO ClientInfo (SSN, FirstName, LastName, PhoneNumber, AddressLine1, AddressLine2, ZipCode, City, State, Birthday) VALUES (715440663, 'David', 'Strum', '702-802-2739','windy hill','redlake','37061', 'Chicago', 'IL', '1963-06-02');

CREATE TABLE HomeInsurance (
 
	 HomePolicyID INT NOT NULL AUTO_INCREMENT,
	 SSN INTEGER(11),  
     PolicyStatus VARCHAR(8),
     CoverageLevel VARCHAR(10),  
     EnrollmentDate DATE,
     ExpirationDate DATE,
     PropertiesInsured INTEGER,
     PRIMARY KEY (HomePolicyID),
     FOREIGN KEY (SSN) REFERENCES ClientInfo (SSN)
);

INSERT INTO HomeInsurance (HomePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, PropertiesInsured) VALUES ('235601911',123456789, 'Active', 'Full', '2023-11-29','2024-11-29', 4); 
INSERT INTO HomeInsurance (HomePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, PropertiesInsured) VALUES ('902121889',448611224, 'Inactive', 'None', '2020-05-14','2021-05-14', 0); 
INSERT INTO HomeInsurance (HomePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, PropertiesInsured) VALUES ('634654742',996135628, 'Inactive', 'None', '2017-09-06','2018-09-06', 0); 
INSERT INTO HomeInsurance (HomePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, PropertiesInsured) VALUES ('896508135',641889133, 'Active', 'Standard', '2023-09-07','2024-09-07', 1); 
INSERT INTO HomeInsurance (HomePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, PropertiesInsured) VALUES ('127861619',715440663, 'Inactive', 'None', '2014-04-07','2015-04-07', 0); 


CREATE TABLE AutoInsurance (
 
	 AutoPolicyID INT NOT NULL AUTO_INCREMENT,
	 SSN INTEGER(11),  
     PolicyStatus VARCHAR(8),
     CoverageLevel VARCHAR(10),  
     EnrollmentDate DATE,
     ExpirationDate DATE,
     VehiclesInsured INTEGER,
     PRIMARY KEY (AutoPolicyID),
     FOREIGN KEY (SSN) REFERENCES ClientInfo (SSN)
);

INSERT INTO AutoInsurance (AutoPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, VehiclesInsured) VALUES ('235601911 ',123456789, 'Active', 'Full', '2023-11-29','2024-11-29', 4); 
INSERT INTO AutoInsurance (AutoPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, VehiclesInsured) VALUES ('902121889',448611224, 'Inactive', 'None', '2020-05-14','2021-05-14', 0); 
INSERT INTO AutoInsurance (AutoPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, VehiclesInsured) VALUES ('634654742',996135628, 'Inactive', 'None', '2017-09-06','2018-09-06', 0); 
INSERT INTO AutoInsurance (AutoPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, VehiclesInsured) VALUES ('896508135',641889133, 'Active', 'Standard', '2023-09-07','2024-09-07', 1); 
INSERT INTO AutoInsurance (AutoPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate, VehiclesInsured) VALUES ('033481849',715440663, 'Active', 'Full', '2023-04-03','2024-04-03', 2); 


CREATE TABLE LifeInsurance (
	 LifePolicyID INT NOT NULL AUTO_INCREMENT,
	 SSN INTEGER(11),  
     PolicyStatus VARCHAR(8),
     CoverageLevel VARCHAR(10),  
     EnrollmentDate DATE,
     ExpirationDate DATE,
	 PRIMARY KEY (LifePolicyID),
     FOREIGN KEY (SSN) REFERENCES ClientInfo (SSN)
);

INSERT INTO LifeInsurance (LifePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('235601911 ',123456789, 'Active', 'Full', '2023-11-29','2024-11-29'); 
INSERT INTO LifeInsurance (LifePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('902121889',448611224, 'Inactive', 'None', '2020-05-14','2021-05-14'); 
INSERT INTO LifeInsurance (LifePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('634654742',996135628, 'Inactive', 'None', '2017-09-06','2018-09-06'); 
INSERT INTO LifeInsurance (LifePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('896508135',641889133, 'Active', 'Standard', '2023-09-07','2024-09-07'); 
INSERT INTO LifeInsurance (LifePolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('791274958',715440663, 'Active', 'Standard', '2023-02-13','2024-02-13'); 



CREATE TABLE HealthInsurance (
 
	 HealthPolicyID INT NOT NULL AUTO_INCREMENT,
	 SSN INTEGER(11),   
     PolicyStatus VARCHAR(8),
     CoverageLevel VARCHAR(10),  
     EnrollmentDate DATE,
     ExpirationDate DATE,
     PRIMARY KEY (HealthPolicyID),
     FOREIGN KEY (SSN) REFERENCES ClientInfo (SSN)
);

INSERT INTO HealthInsurance (HealthPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('235601911 ',123456789, 'Active', 'Full', '2023-11-29','2024-11-29'); 
INSERT INTO HealthInsurance (HealthPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('902121889',448611224, 'Inactive', 'None', '2020-05-14','2021-05-14'); 
INSERT INTO HealthInsurance (HealthPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('634654742',996135628, 'Inactive', 'None', '2017-09-06','2018-09-06'); 
INSERT INTO HealthInsurance (HealthPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('896508135',641889133, 'Active', 'Standard', '2023-09-07','2024-09-07'); 
INSERT INTO HealthInsurance (HealthPolicyID, SSN, PolicyStatus, CoverageLevel, EnrollmentDate, ExpirationDate) VALUES ('028606523',715440663, 'Inactive', 'None', '2000-01-19','2001-01-19'); 