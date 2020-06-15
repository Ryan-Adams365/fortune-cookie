var mysql = require('mysql');
var pool = mysql.createPool({
  connectionLimit : 10,
  host            : 'classmysql.engr.oregonstate.edu',
  user            : 'cs340_adamsrya',
  password        : '6091',
  database        : 'cs340_adamsrya'
});
module.exports.pool = pool;