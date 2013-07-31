'use strict';

var assert = require('assert');
var fei = require('../');

assert.ok(fei.init());
assert.ifError(fei.terminate());

assert.equal(typeof fei.getVersion(), 'object');
assert.equal(typeof fei.getVersionString(), 'string');

assert.equal(typeof fei.GLFW_VERSION_MAJOR, 'number');
assert.equal(typeof fei.GLFW_VERSION_MINOR, 'number');
assert.equal(typeof fei.GLFW_VERSION_REVISION, 'number');
