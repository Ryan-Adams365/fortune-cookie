/* Express Module */
var express = require('express');
var app = express();
app.set('port', 9876);
var path = require('path');
app.use(express.static(path.join(__dirname, '/public')));

/* Handlebars Module */
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');

/* BodyParser Module */
var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

/* MySQL Module */
var mysql = require('./dbcon.js');
app.set('mysql', mysql);

/* Page Modules */
app.use('/recipes', require('./recipes.js'));
//app.use('/meal-plans', require('./meal-plans.js'));
app.use('/', require('./home.js'));

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on flipx.engr.oregonstate.edu:' + app.get('port') + '; press Ctrl-C to terminate.');
});
