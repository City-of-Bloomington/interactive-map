<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
$rf = new \Aura\Router\RouterFactory(BASE_URI);
$ROUTES = $rf->newInstance();

$ROUTES->add('home', '/')->setValues(['controller'=>'maps', 'action'=>'index']);

$ROUTES->attach('maps', '/maps', function ($r) {
    $r->setTokens(['id'=>'[a-z0-9\-]+']);
    $r->setValues(['controller'=>'maps']);

    $r->add('index',    '')              ->addValues(['action'=>'index'   ]);
    $r->add('update',   '/update{/id}')  ->addValues(['action'=>'update'  ]);
    $r->add('delete',   '/delete{/id}')  ->addValues(['action'=>'delete'  ]);
    $r->add('view',     '/{id}')         ->addValues(['action'=>'view'    ]);
    $r->add('download', '/download/{id}')->addValues(['action'=>'download']);
});

$ROUTES->attach('login', '/login', function ($r) {
    $r->setValues(['controller'=>'login']);

    $r->add('index',  '')       ->addValues(['action'=>'index' ]);
    $r->add('login',  '/login') ->addValues(['action'=>'login' ]);
    $r->add('logout', '/logout')->addValues(['action'=>'logout']);
});

$ROUTES->attach('people', '/people', function ($r) {
    $r->setTokens(['id'=>'[0-9]+']);
    $r->setValues(['controller'=>'people']);

    $r->add('index',  '')            ->addValues(['action'=>'index' ]);
    $r->add('view',   '/{id}')       ->addValues(['action'=>'view'  ]);
    $r->add('update', '/update{/id}')->addValues(['action'=>'update']);
});

$ROUTES->attach('users', '/users', function ($r) {
    $r->setTokens(['id'=>'[a-z0-9]+']);
    $r->setValues(['controller'=>'users']);

    $r->add('index',  '')             ->addValues(['action'=>'index' ]);
    $r->add('update', '/update{/id}') ->addValues(['action'=>'update']);
    $r->add('delete', '/delete/{id}') ->addValues(['action'=>'delete']);
});
