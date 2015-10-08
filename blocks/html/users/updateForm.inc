<?php
/**
 * @copyright 2006-2014 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param User $this->user
 */
use Application\Models\Person;
use Blossom\Classes\View;

$title = $this->user->getId() ? $this->_('user_edit') : $this->_('user_add');
?>
<section>
    <h1><?php echo $title; ?></h1>
	<form method="post" action="<?php echo BASE_URI; ?>/users/update">
		<fieldset><legend><?php echo $this->_('user_info'); ?></legend>
			<input name="user_id" type="hidden" value="<?php echo $this->user->getId(); ?>" />

            <dl><dt><label for="authenticationMethod"><?php echo $this->_('authenticationMethod'); ?></label></dt>
                <dd><select name="authenticationMethod" id="authenticationMethod" required="required">
                    <?php
                        foreach (Person::getAuthenticationMethods() as $method) {
                            $selected = $this->user->getAuthenticationMethod()==$method
                                ? 'selected="selected"'
                                : '';
                            echo "<option $selected>$method</option>";
                        }
                    ?>
                    </select>
                </dd>
            </dl>
            <dl><dt><label for="username"><?php echo $this->_('username'); ?></label></dt>
                <dd><input name="username" id="username" value="<?php echo View::escape($this->user->getUsername()); ?>"
                        required="required" />
                </dd>
            </dl>
            <dl><dt><label for="password"><?php echo $this->_('password'); ?></label></dt>
                <dd><input name="password" id="password" type="password" /></dd>
            </dl>
            <dl><dt><label for="role"><?php echo $this->_('role'); ?></label></dt>
                <dd><select name="role" id="role"><option></option>
                    <?php
                        global $ZEND_ACL;
                        foreach (array_reverse($ZEND_ACL->getRoles()) as $role) {
                            $selected = $this->user->getRole()==$role
                                ? 'selected="selected"'
                                : '';
                            echo "<option $selected>$role</option>";
                        }
                    ?>
                    </select>
                </dd>
            </dl>
			<?php
				$helper = $this->template->getHelper('saveAndCancelButtons');
				echo $helper->saveAndCancelButtons(BASE_URI.'/users');
			?>
		</fieldset>
	</form>
</section>